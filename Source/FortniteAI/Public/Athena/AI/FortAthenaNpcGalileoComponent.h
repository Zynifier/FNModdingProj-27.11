// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/MathFwd.h"
#include "FortAthenaNpcGalileoComponent.generated.h"

class AActor;
class AController;
class AFortAthenaAIBotController;
class AFortPawn;
class UPrimitiveComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGalileoComponentOnPatrollingStart);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGalileoComponentOnPatrollingStop);

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class UFortAthenaNpcGalileoComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	const TArray<AFortAthenaAIBotController*>& GetCommunicationGroup();

	UFUNCTION(BlueprintPure)
	const TArray<FVector>& GetPatrolPath() const;

	UFUNCTION()
	void OnPawnDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION(BlueprintCallable)
	void SetCommunicationGroup(const TArray<AFortAthenaAIBotController*>& AIBotControllerList);

	UFUNCTION(BlueprintCallable)
	void SetPatrolPath(const TArray<FVector>& NewPatrolPath);

private:
	UPROPERTY(Transient)
	TObjectPtr<AFortAthenaAIBotController> CachedBotController;

	UPROPERTY(Transient)
	TObjectPtr<AFortPawn> PossessedPawn;

	UPROPERTY(Transient)
	TArray<FVector> PatrolPath;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortAthenaAIBotController>> CommunicationGroup;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FGalileoComponentOnPatrollingStart OnPatrollingStart;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FGalileoComponentOnPatrollingStop OnPatrollingStop;

};

