#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/HitInterface.h"
#include "Characters/CharacterTypes.h"
#include "Enemy.generated.h"

class UAnimMontage;
class UAttributeComponent;
class UHealthBarComponent;
class UPawnSensingComponent;

UCLASS()
class SLASH_API AEnemy : public ACharacter,public IHitInterface
{
	GENERATED_BODY()

public:
	AEnemy();
	virtual void Tick(float DeltaTime) override;
	void CheckPatrolTarget();
	void CheckCombatTarget();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void GetHit_Implementation(const FVector& ImpactPoint) override;
	void DirectionalHitReact(const FVector& ImpactPoint);
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
private:
	UPROPERTY(EditAnywhere)
	UAttributeComponent* Attributes;

	UPROPERTY(EditAnywhere)
	UHealthBarComponent* HealthBarWidget;

	UPROPERTY(EditDefaultsOnly,Category = Montage)
	UAnimMontage* HitReactMontage;

	UPROPERTY(EditDefaultsOnly, Category = Montage)
	UAnimMontage* DeathMontage;

	UPROPERTY(EditAnywhere,Category = Sounds)
	USoundBase* HitSound ;

	UPROPERTY(EditAnywhere,Category = VisualEffects)
	UParticleSystem* HitParticles ;

	UPROPERTY()
	AActor* CombatTarget;

	UPROPERTY(EditAnywhere)
	double CombatRadius = 500.f;

	UPROPERTY(EditInstanceOnly, Category = "AI Navigation")
	AActor* PatrolTarget;

	UPROPERTY(EditInstanceOnly, Category = "AI Navigation")
	TArray<AActor*> PatrolTargets;

	UPROPERTY(EditAnywhere)
	double PatrolRadius = 200.f;

	UPROPERTY(EditAnywhere, Category = "Death")
	float DeathLifeSpan = 5.f;

	FTimerHandle PatrolTimer;
	void PatrolTimerFinished();

	UPROPERTY(EditAnywhere,Category = "AI Navigation")
	float WaitMin = 3.f;

	UPROPERTY(EditAnywhere, Category = "AI Navigation")
	float WaitMax = 8.f;

	UPROPERTY(VisibleAnywhere)
	UPawnSensingComponent* PawnSensing;

	UPROPERTY()
	class AAIController* EnemyController;

	EEnemyState EnemyState = EEnemyState::EES_Patrolling;
protected:
	virtual void BeginPlay() override;
	void Die();
	bool InTargetRange(AActor* Target, double Radius);
	void PlayHitReactMontage(const FName& SectionName);
	void MoveToTarget(AActor* Target);
	UFUNCTION()
	void PawnSeen(APawn* SeenPawn);

	AActor* ChoosePatrolTarget();
	UPROPERTY(BlueprintReadOnly)
	EDeathPose DeathPose = EDeathPose::EDP_Alive;
public:	
};
