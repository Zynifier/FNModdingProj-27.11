// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Conversation/FortConversationTaskNode_Service.h"
#include "FortConversationTaskNode_SupplyDrop.generated.h"

class UFortSupplyDropInfo;

UENUM(BlueprintType)
enum class EPreventSupplyDropUseReason : uint8
{
	CannotAfford = 0,
	OutOfStock = 1,
	None = 2 UMETA(Hidden),
	Count = 3 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class ESupplyDropSpawnLocationPolicy : uint8
{
	// Supply drops will only be placed within a specified distance of the NPC

	RadiusAroundLocation = 0,
	// Supply drops will be placed anywhere within the current safe zone

	SafeZone = 1,
};

USTRUCT()
struct FPendingSupplyDropInfo
{
	GENERATED_BODY()

};

USTRUCT()
struct FSupplyDropTaskMemory
{
	GENERATED_BODY()

};

UCLASS(Abstract)
class UFortConversationTaskNode_SupplyDrop : public UFortConversationTaskNode_Service
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="SupplyDrop")
	TSoftObjectPtr<UFortSupplyDropInfo> SupplyDropInfo;

	UPROPERTY(EditDefaultsOnly, Category="SupplyDrop")
	FScalableFloat SupplyDropCount;

	UPROPERTY(EditDefaultsOnly, Category="SupplyDrop")
	FScalableFloat ProcessPendingSupplyDropInterval;

	UPROPERTY(EditDefaultsOnly, Category="SupplyDrop")
	FScalableFloat GuaranteedCloseRangeSupplyDropCount;

	UPROPERTY(EditDefaultsOnly, Category="SupplyDrop")
	FGameplayTag ServiceUsedTag;

	UPROPERTY(EditDefaultsOnly, Category="SupplyDrop|RadiusOrLocation")
	FScalableFloat GuaranteedCloseRangeRadiusAroundNPC;

	UPROPERTY(EditDefaultsOnly, Category="SupplyDrop|RadiusOrLocation")
	ESupplyDropSpawnLocationPolicy SupplyDropLocationPolicy;

	UPROPERTY(EditDefaultsOnly, Category="SupplyDrop|RadiusOrLocation")
	FScalableFloat RadiusAroundNPC;

	UPROPERTY(EditDefaultsOnly, Category="SupplyDrop|RadiusOrLocation")
	FScalableFloat SpawnInPreviousSafeAreaChanceZeroToOne;

	UPROPERTY(EditDefaultsOnly, Category="SupplyDrop|Stock")
	bool bLimitedStock;

	UPROPERTY(EditDefaultsOnly, Category="SupplyDrop|Stock", meta=(editCondition="bLimitedStock"))
	FScalableFloat LimitedStockCount;

	UPROPERTY(EditDefaultsOnly, Category="FortConversationTaskNode_SupplyDrop", meta=(Categories="SupplyDrop|Cosmetics"))
	FGameplayTag CustomFeedMessageTag;

};

