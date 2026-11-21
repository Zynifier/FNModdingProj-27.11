// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AthenaMapScreenContainerTabInterface.generated.h"

class AFortMinigame;
class UObject;

USTRUCT()
struct FAthenaMapScreenContainerTabInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AthenaMapScreenContainerTabInfo")
	FText TabTitle;

	UPROPERTY(EditAnywhere, Category="AthenaMapScreenContainerTabInfo", meta=(AllowedClasses="/Script/Engine.MaterialInterface,/Script/Engine.Texture2D"))
	TSoftObjectPtr<UObject> TabIcon;

	UPROPERTY(EditAnywhere, Category="AthenaMapScreenContainerTabInfo")
	int32 Order;

	UPROPERTY(EditAnywhere, Category="AthenaMapScreenContainerTabInfo")
	bool bDefaultFrontendActiveTab;

	UPROPERTY(EditAnywhere, Category="AthenaMapScreenContainerTabInfo")
	bool bDefaultInGameActiveTab;

	UPROPERTY(EditAnywhere, Category="AthenaMapScreenContainerTabInfo")
	bool bShowPlayerProfile;

	UPROPERTY(EditAnywhere, Category="AthenaMapScreenContainerTabInfo")
	FName TabID;

};

UINTERFACE(MinimalAPI)
class UAthenaMapScreenContainerTabInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEUI_API IAthenaMapScreenContainerTabInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	bool OnHandleMapBackAction(bool& bOutBackActionHandled);

	UFUNCTION(BlueprintImplementableEvent)
	bool OnShouldCreateMapScreenTab(bool& bOutShouldCreateMapScreenTab, const UObject* WorldContextObject) const;

	UFUNCTION(BlueprintImplementableEvent)
	bool OnShouldDisplayBackActionInActionBar(bool& bOutShouldDisplayBackActionInActionBar) const;

	UFUNCTION(BlueprintImplementableEvent)
	bool OnShouldShowTabOnMapScreenForMinigame(bool& bOutShouldShowTabOnMapScreenForMinigame, const AFortMinigame* Minigame) const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnTabAddedToMapScreenContainer();

};

