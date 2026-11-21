// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "FortAIComponent_Telemetry.generated.h"

class AActor;
class AAthenaAIController;
class AController;
class AFortAIPawn;
class AFortPawn;
class UFortAthenaAIRuntimeParameters_AIAnalytic;
class UFortAthenaAITelemetryData;
class UFortItemDefinition;
class UPrimitiveComponent;

UENUM()
enum class EAthenaAITelemetryEventType : uint8
{
	Spawn = 0,
	Despawn = 1,
};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class UFortAIComponent_Telemetry : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	FORTNITEAI_API UFortAthenaAITelemetryData* GetOrCreateTelemetryData(const TSubclassOf<UFortAthenaAITelemetryData> TelemetryDataClass);

protected:
	UPROPERTY(Transient)
	TObjectPtr<AFortAIPawn> PossessedPawn;

	UPROPERTY(Transient)
	TObjectPtr<AAthenaAIController> CachedAIController;

private:
	UFUNCTION()
	FORTNITEAI_API void OnDidDamage(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	FORTNITEAI_API void OnPawnDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	FORTNITEAI_API void OnTetheredFollowerChanged(AFortPawn* NewFollower, AFortPawn* OldFollower);

	UPROPERTY(Transient)
	TObjectPtr<AController> DeathInstigator;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortItemDefinition>> GrabbedPickups;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortItemDefinition>> DroppedPickups;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIRuntimeParameters_AIAnalytic> AnalyticRuntimeParameters;

	UPROPERTY(Transient)
	TArray<UFortAthenaAITelemetryData*> TelemetryData;

};

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class UFortAthenaAITelemetryData : public UObject
{
	GENERATED_BODY()

};

UCLASS()
class UFortAthenaAITelemetryFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AI Telemetry")
	static UFortAthenaAITelemetryData* GetOrCreateAITelemetryData(const AActor* Owner, const TSubclassOf<UFortAthenaAITelemetryData> TelemetryDataClass);

};

