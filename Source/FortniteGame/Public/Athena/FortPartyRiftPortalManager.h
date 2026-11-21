// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "FortPartyRiftPortalManager.generated.h"

class AFortAthenaPartyRiftPortal;
class AFortPartyRiftPortalManager;
class AFortPlayerController;
class AFortPlayerControllerAthena;
class AFortPlayerPawn;
class UObject;
enum class EPartyRiftPortalManagerValidityResult : uint8;

UENUM(BlueprintType)
enum class EPartyRiftPortalManagerValidityResult : uint8
{
	Valid = 0,
	Invalid = 1,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPartyRiftPortalManagerPortalUpdated, AFortPlayerControllerAthena*, PortalOwnerController);

UCLASS(Config=Game, DefaultConfig, MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortPartyRiftPortalManager : public AInfo
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool CanSpawnPortal(const AFortPlayerController* PlayerController, FGameplayTagContainer& OutResultTags) const;

	UFUNCTION(BlueprintPure)
	bool DeterminePortalSpawnLocation(AFortPlayerPawn* PlayerPawn, FVector& Location, FRotator& Rotation) const;

	UFUNCTION(BlueprintCallable, meta=(ExpandEnumAsExecs="OutIsValid", WorldContext="WorldContextObject"))
	static void GetPartyRiftPortalManager(const UObject* WorldContextObject, AFortPartyRiftPortalManager*& OutPartyRiftPortalManager, EPartyRiftPortalManagerValidityResult& OutIsValid);

	UFUNCTION(BlueprintCallable)
	void ReleasePortal(AFortAthenaPartyRiftPortal* PortalToRelease, const FString& Reason);

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortPartyRiftPortalManager")
	FScalableFloat MinimumSpawnSeparation;

	UPROPERTY(EditDefaultsOnly, Category="FortPartyRiftPortalManager")
	FScalableFloat PortalSpawnDistance;

	UPROPERTY(EditDefaultsOnly, Category="FortPartyRiftPortalManager")
	FScalableFloat VerticalSpawnDistance;

	UPROPERTY(EditDefaultsOnly, Category="FortPartyRiftPortalManager")
	FScalableFloat MaxHeightFromPawn;

	UPROPERTY(EditDefaultsOnly, Category="FortPartyRiftPortalManager")
	FScalableFloat MaxHeightAboveTerrain;

	UPROPERTY(EditDefaultsOnly, Category="FortPartyRiftPortalManager")
	FVector BoxHalfSize;

	UPROPERTY(EditDefaultsOnly, Category="FortPartyRiftPortalManager")
	FGameplayTagContainer PrivacyErrorTags;

	UPROPERTY(EditDefaultsOnly, Category="FortPartyRiftPortalManager")
	FGameplayTagContainer CollisionErrorTags;

	UPROPERTY(EditDefaultsOnly, Category="FortPartyRiftPortalManager")
	FGameplayTagContainer TooCloseErrorTags;

	UPROPERTY(EditDefaultsOnly, Category="FortPartyRiftPortalManager")
	FGameplayTagContainer NotLeaderErrorTags;

	UPROPERTY(EditDefaultsOnly, Category="FortPartyRiftPortalManager")
	FGameplayTagContainer GuestErrorTags;

	UPROPERTY(EditDefaultsOnly, Category="FortPartyRiftPortalManager")
	FGameplayTagContainer HubErrorTags;

	UPROPERTY(EditDefaultsOnly, Category="FortPartyRiftPortalManager")
	FGameplayTagContainer PartyFullErrorTags;

	UPROPERTY(EditDefaultsOnly, Category="FortPartyRiftPortalManager")
	FGameplayTagContainer AwayErrorTags;

	UPROPERTY(EditDefaultsOnly, Category="FortPartyRiftPortalManager")
	float LongRangeInteractionMinimumDistance;

	UPROPERTY(BlueprintReadOnly, Category="FortPartyRiftPortalManager")
	float LongRangeInteractionMaximumDistance;

	UPROPERTY(BlueprintReadOnly, Category="FortPartyRiftPortalManager")
	float LongRangeInteractionCutoffAngle;

private:
	UPROPERTY(Transient, Replicated)
	TArray<TObjectPtr<AFortAthenaPartyRiftPortal>> AllPortals;

	UPROPERTY(Transient)
	TMap<TObjectPtr<AFortPlayerControllerAthena>, TObjectPtr<AFortAthenaPartyRiftPortal>> PortalMap;

};

