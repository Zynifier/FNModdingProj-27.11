// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "AI/FortAITypes.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_Telemetry.generated.h"

class AActor;
class AFortPickup;
class UFortWeaponItemDefinition;

USTRUCT()
struct FContentOnDemandTelemetryInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, NotReplicated)
	int32 TotalNumCompleted;

	UPROPERTY(Transient, NotReplicated)
	int32 TotalNumCompletedWithInstall;

	UPROPERTY(Transient, NotReplicated)
	int32 NumCompletdWithErrors;

	UPROPERTY(Transient, NotReplicated)
	double TotalInstallTime;

};

USTRUCT()
struct FFortBotNavLinkTimeoutInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FVector Position;

	UPROPERTY(Transient)
	uint32 LinkID;

	UPROPERTY(Transient)
	FString NavAreaName;

};

USTRUCT()
struct FFortBotTeleportInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	bool bTeleportSuccess;

	UPROPERTY(Transient)
	FVector TeleportFrom;

	UPROPERTY(Transient)
	FRotator RotationFrom;

	UPROPERTY(Transient)
	FVector TeleportTo;

	UPROPERTY(Transient)
	FRotator RotationTo;

	UPROPERTY(Transient)
	ETeleportReason TeleportReason;

	UPROPERTY(Transient)
	FString BTNodeNameCausingTeleportation;

};

USTRUCT()
struct FFortItemsConsumedInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<UFortWeaponItemDefinition> WeaponData;

	UPROPERTY(Transient)
	FVector Location;

	UPROPERTY(Transient)
	float Health;

	UPROPERTY(Transient)
	float Shield;

	UPROPERTY(Transient)
	int32 ItemQuantity;

};

USTRUCT()
struct FFortRevivedInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FVector RevivedLocation;

	UPROPERTY(Transient)
	FString ReviverUniqueID;

	UPROPERTY(Transient)
	uint8 ReviverTeam;

};

USTRUCT()
struct FPawnConvertedInfos
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ConvertedPawnUniqueID;

};

USTRUCT()
struct FPlayerFishingTelemetryData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, NotReplicated, Category="Fishing")
	float TimeFishingSessionBegan;

	UPROPERTY(EditAnywhere, NotReplicated, Category="Fishing")
	TWeakObjectPtr<AFortPickup> Item;

	UPROPERTY(EditAnywhere, NotReplicated, Category="Fishing")
	TWeakObjectPtr<AActor> ItemUsedToFish;

	UPROPERTY(EditAnywhere, NotReplicated, Category="Fishing")
	bool bFromFishingPool;

	UPROPERTY(EditAnywhere, NotReplicated, Category="Fishing")
	bool bBestCollected;

	UPROPERTY(EditAnywhere, NotReplicated, Category="Fishing")
	FString FishVariantTag;

	UPROPERTY(EditAnywhere, NotReplicated, Category="Fishing")
	float FishPropertyLength;

};

UCLASS(Config=Game, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_Telemetry : public UFortControllerComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TArray<FFortBotTeleportInfo> Teleports;

	UPROPERTY(Transient)
	int32 TotalTeleports;

	UPROPERTY(Transient)
	TArray<FFortBotNavLinkTimeoutInfo> NavLinkTimeouts;

	UPROPERTY(Transient)
	int32 TotalNavLinkTimeouts;

	UPROPERTY(Transient)
	int32 TotalAmmoCheats;

	UPROPERTY(Transient)
	float SpawnTime;

	UPROPERTY(Transient)
	FPlayerFishingTelemetryData PlayerFishingTelemetryData;

	UPROPERTY(Transient)
	TArray<FFortItemsConsumedInfo> ItemsConsumed;

	UPROPERTY(Transient)
	int32 TotalItemsConsumed;

	UPROPERTY(Transient)
	TArray<FFortRevivedInfo> Revived;

	UPROPERTY(Transient)
	int32 TotalTimesRevived;

	UPROPERTY(Transient)
	bool bHasLandedFromSkyDiving;

	UPROPERTY(Transient)
	FVector SkyDiveJumpLocation;

	UPROPERTY(Transient)
	FVector SkyDiveLandLocation;

	UPROPERTY(Transient)
	int32 SkyDiveLandAsyncQueue;

	UPROPERTY(Transient)
	FString SkyDiveLandPOITags;

	UPROPERTY(EditAnywhere, Category="FortControllerComponent_Telemetry")
	FGameplayTagContainer IgnoreTelemetryCapForConsumedItems;

private:
	UPROPERTY()
	TArray<FPawnConvertedInfos> PawnsConverted;

	UPROPERTY(Transient)
	FContentOnDemandTelemetryInfo ContentOnDemandRequestInfo;

};

