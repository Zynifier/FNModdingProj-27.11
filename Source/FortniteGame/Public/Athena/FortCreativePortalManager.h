// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "FortCreativePortalManager.generated.h"

class AFortAthenaCreativePortal;
class AFortCreativePortalManager;
class AFortPlayerController;
class AFortPlayerControllerAthena;
class UObject;
enum class ECreativePortalManagerValidityResult : uint8;

UENUM(BlueprintType)
enum class ECreativePortalManagerValidityResult : uint8
{
	Valid = 0,
	Invalid = 1,
};

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortCreativePortalManager : public AInfo
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Volume", meta=(ExpandEnumAsExecs="OutIsValid", WorldContext="WorldContextObject"))
	static void GetCreativePortalManager(const UObject* WorldContextObject, AFortCreativePortalManager*& OutCreativePortalManager, ECreativePortalManagerValidityResult& OutIsValid);

	UFUNCTION()
	void OnPendingReservationPartyLeaderSet(AFortPlayerController* PlayerController);

	UFUNCTION(BlueprintCallable)
	void ReleasePortal(AFortAthenaCreativePortal* PortalToRelease);

private:
	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortAthenaCreativePortal>> AllPortals;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<AFortPlayerControllerAthena>> PendingPortalReservations;

};

