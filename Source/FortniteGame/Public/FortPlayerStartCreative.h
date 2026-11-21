// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameFramework/PlayerStart.h"
#include "GameplayTagContainer.h"
#include "FortPlayerStartCreative.generated.h"

class UFortCreativeVolumeLinkComponent;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Collision", "Lighting", "LightColor", "Force"))
class AFortPlayerStartCreative : public APlayerStart
{
	GENERATED_BODY()

public:
	AFortPlayerStartCreative(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintNativeEvent)
	bool AreSpecialClaimingConditionsMet() const;

	UFUNCTION(BlueprintPure)
	bool IsClaimedByPlayer(FUniqueNetIdRepl UniqueId) const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPlayerStartCreative")
	FGameplayTagContainer PlayerStartTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPlayerStartCreative")
	int32 PortalIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPlayerStartCreative")
	uint8 ApplicableTeam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPlayerStartCreative")
	int32 ApplicableClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPlayerStartCreative")
	bool bUseAsIslandStart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPlayerStartCreative")
	int32 PriorityGroup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPlayerStartCreative")
	float EnemyRangeCheck;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPlayerStartCreative")
	FString LockedPlayerNameSubstring;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortPlayerStartCreative")
	bool bIsEnabled;

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="FortPlayerStartCreative", meta=(EditInline="true"))
	TObjectPtr<UFortCreativeVolumeLinkComponent> CreativeLinkComponent;

private:
	UFUNCTION()
	void OnMinigameStarted();

};

