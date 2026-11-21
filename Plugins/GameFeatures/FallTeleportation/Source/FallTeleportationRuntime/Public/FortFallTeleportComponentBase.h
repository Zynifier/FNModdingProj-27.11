// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "FortFallTeleportComponentBase.generated.h"

class AActor;
class ACharacter;
class AFortPlayerPawnAthena;
class UGameplayEffect;

UCLASS(BlueprintType, Blueprintable, PrioritizeCategories=("Teleport", "Teleport", "Modifiers", "Blocklist", "Failsafe", "Teleport", "Configs"))
class FALLTELEPORTATIONRUNTIME_API UFortFallTeleportComponentBase : public UActorComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	bool IsTeleportLocationValid(const FVector& LocationToTest) const;

	UFUNCTION(BlueprintPure)
	bool IsValidActorToTeleportOn(AActor* ActorToTeleportOn) const;

	UFUNCTION()
	void UpdateLastGroundLocation(ACharacter* Character, EMovementMode PrevMovementMode, uint8 PreviousCustomMode);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Teleport Configs")
	FScalableFloat TeleportEnabled;

	UPROPERTY(EditDefaultsOnly, Config, Category="Teleport Configs")
	FScalableFloat ContinuousTeleportUpdateEnabled;

	UPROPERTY(EditDefaultsOnly, Config, Category="Teleport Configs")
	FScalableFloat ForceTeleportZHeight;

	UPROPERTY(EditDefaultsOnly, Config, Category="Teleport Configs")
	FScalableFloat SphereTraceRadius;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Teleport Modifiers")
	float WalkingLocationUpdateRate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Teleport Modifiers")
	float ZHeightThresholdCheckRate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Teleport Modifiers")
	float TeleportZModifier;

	UPROPERTY(EditDefaultsOnly, Category="Teleport Modifiers")
	float DistanceFromPawnToTraceLocation;

	UPROPERTY(EditDefaultsOnly, Category="Blocklist")
	TArray<TSubclassOf<AActor>> TeleportOnBlocklist;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Blocklist")
	FName NoTeleportActorTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Teleport")
	FVector SafeManualLocation;

	UPROPERTY(EditDefaultsOnly, Category="Teleport")
	TSubclassOf<UGameplayEffect> TeleportGEClass;

	UPROPERTY(BlueprintReadOnly, Category="Teleport")
	FVector TeleportLocation;

	UPROPERTY(BlueprintReadOnly, Category="Teleport")
	FVector FallbackLocation;

	UPROPERTY(BlueprintReadWrite, Category="Teleport")
	bool bValidFallbackLocation;

	UPROPERTY(BlueprintReadWrite, Category="Teleport")
	bool bTeleporting;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Failsafe")
	int32 TeleportLimitBeforeFail;

	UPROPERTY(BlueprintReadWrite, Category="Failsafe")
	int32 TeleportCount;

	UPROPERTY(BlueprintReadOnly, Category="FortFallTeleportComponentBase")
	AFortPlayerPawnAthena* OwningPawn;

};

