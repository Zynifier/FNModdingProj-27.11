// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Creative/FortCreativeIconOption.h"
#include "CreativeClassSelectorButton.h"
#include "Minigame/FortMinigame.h"
#include "ClassSelectorTeamTile.generated.h"

class UCommonLazyImage;
class UTextBlock;

UCLASS()
class UClassSelectorTeamTile : public UCreativeClassSelectorButton
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayerCountSet(int32 NewPlayerCount);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTeamColorIndexSet(int32 TeamColorIndex);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTeamIconSet(const FCreativeIconOption& NewTeamIcon);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTeamSet(const FMinigameTeam& NewTeamData);

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="ClassSelectorTeamTile", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> PlayerCount;

	UPROPERTY(BlueprintReadOnly, Export, Category="ClassSelectorTeamTile", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonLazyImage> TeamIconImage;

};

