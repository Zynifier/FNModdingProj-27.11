// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/FortCheatManager.h"
#include "FortCheatManagerAthena.generated.h"

enum class EFortContentRating : uint8;

UCLASS()
class UFortCheatManagerAthena : public UChildCheatManager
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void ContentGatingAddUnlock(const FString& Category, const FString& Subcategory);

	UFUNCTION(Exec)
	void ContentGatingRemoveUnlock(const FString& Category, const FString& Subcategory);

	UFUNCTION(Exec)
	void ContentGatingSetRating(EFortContentRating Rating);

	UFUNCTION(Exec)
	void DumpAllGameplayAbilitiesForActor();

	UFUNCTION(Exec)
	void DumpAllOwnedTags();

	UFUNCTION(Exec)
	void DumpAllOwnedTagsForActor();

	UFUNCTION(Exec)
	void DumpNavigationInvokersState();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ForceDynamicStormCirclePlayerCount(const int32 Count);

	UFUNCTION(Exec)
	void GiveCreativeItem(const FString& DevicePath, const int32 SlotIndex = 1);

	UFUNCTION(Exec)
	void McpSetOwnedCosmetics(const FString& VersionString);

	UFUNCTION(Exec)
	void RemoveAllRebootVans();

	UFUNCTION(Exec)
	void RevealNearbyItemOrigins(float RevealRadius = 500.000000f);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SafeZoneStartNextPhase();

	UFUNCTION(Exec)
	void SetAlwaysShowContrails(bool bEnabled);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetSafeZoneLocationToMarker();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetSafeZoneLocationToPlayer();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetSafeZonePhase(int32 NewPhaseIndex);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetSafeZoneRadius(float NewRadius);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetSafeZoneShrinkTime(float NewShrinkTime);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetSafeZoneWaitTime(float NewWaitTime);

	UFUNCTION(Exec, BlueprintCosmetic)
	void SetStormFXStage(int32 NewStormStage);

};

