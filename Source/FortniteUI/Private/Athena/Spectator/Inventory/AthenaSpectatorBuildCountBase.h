// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaSpectatorBuildCountBase.generated.h"

class ABuildingSMActor;
class AFortPlayerControllerSpectating;
class AFortPlayerState;
class UFortItemDefinition;
class UFortWorldItem;

UENUM(BlueprintType)
enum class ESpectatorBuildCountType : uint8
{
	BuildCount = 0,
	Wood = 1,
	Stone = 2,
	Metal = 3,
	Gold = 4,
};

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaSpectatorBuildCountBase : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnBuildCountChanged(int32 OldCount, int32 NewCount);

	UFUNCTION(BlueprintImplementableEvent)
	void OnFollowedPlayerChanged_BP();

	UPROPERTY(EditDefaultsOnly, Category="AthenaSpectatorBuildCountBase")
	TSubclassOf<ABuildingSMActor> BuildingClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaSpectatorBuildCountBase")
	ESpectatorBuildCountType BuildCountType;

	UPROPERTY(EditAnywhere, Category="AthenaSpectatorBuildCountBase")
	TObjectPtr<UFortItemDefinition> ItemDefinition;

private:
	UFUNCTION()
	void OnFollowedPlayerChanged(AFortPlayerControllerSpectating* SpectatingPC, AFortPlayerState* NewFollowedPlayer);

	UFUNCTION()
	void OnWorldItemListChanged(const TArray<UFortWorldItem*>& ItemsAdded, const TArray<UFortWorldItem*>& ItemsRemoved);

	UFUNCTION()
	void UpdateBuildCount();

};

