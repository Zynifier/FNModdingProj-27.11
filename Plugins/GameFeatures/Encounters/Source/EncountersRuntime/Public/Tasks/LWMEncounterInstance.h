// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "Athena/AI/FortPlayerBotUtils.h"
#include "LWMEncounterInstance.generated.h"

class AActor;
class AController;
class AFortPawn;
class IFortAthenaLivingWorldPointProviderInterface;
class UFortAthenaLivingWorldEncounterInstance;
class UGameplayEffect;
class UPrimitiveComponent;

UENUM(BlueprintType)
enum class EAlertLevelComparisonOperator : uint8
{
	GreaterThan = 0,
	LessThan = 1,
	EqualTo = 2,
	NotEqualTo = 3,
	GreaterThanOrEqualTo = 4,
	LessThanOrEqualTo = 5,
};

USTRUCT()
struct FLWMEncounterAlertLevelTargetInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="LWMEncounterAlertLevelTargetInfo")
	EPerceptionState AwarePerceptionState;

	UPROPERTY(EditAnywhere, Category="LWMEncounterAlertLevelTargetInfo")
	float AwareForgetTime;

	UPROPERTY(EditAnywhere, Category="LWMEncounterAlertLevelTargetInfo")
	float AwareForgetDistance;

};

USTRUCT()
struct FLWMEncounterInstanceEffectInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TSubclassOf<UGameplayEffect> GameplayEffect;

};

UCLASS()
class ULWMEncounterInstance : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnMobActorDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* HitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void OnMobActorSpawn(AActor* SpawnedActor);

	UFUNCTION()
	void OnMobPawnEndPlay(AActor* Mob, EEndPlayReason::Type EndPlayReason);

private:
	UPROPERTY(Transient)
	TWeakObjectPtr<UFortAthenaLivingWorldEncounterInstance> LWMInstance;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<AFortPawn>> SpawnedMobPawns;

	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> EncounterAnchorPoint;

	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> UserActor;

	UPROPERTY(Transient)
	TArray<TScriptInterface<IFortAthenaLivingWorldPointProviderInterface>> ActivePointProviderInterfaces;

};

