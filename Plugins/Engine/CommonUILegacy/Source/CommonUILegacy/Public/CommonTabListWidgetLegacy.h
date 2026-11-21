// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonTabListWidgetBase.h"
#include "CommonTabListWidgetLegacy.generated.h"

class UCommonButtonBase;
class UCommonButtonLegacy;

/** Base class for a list of selectable tabs that correspondingly activate and display an arbitrary widget in a linked switcher */
UCLASS(Abstract, BlueprintType, Blueprintable, ClassGroup=("UI"), meta=(Category="Common UI", DisableNativeTick))
class COMMONUILEGACY_API UCommonTabListWidgetLegacy : public UCommonTabListWidgetBase
{
	GENERATED_BODY()

public:
/** Delegate broadcast when a new tab is created. Allows hook ups after creation. */
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTabButtonCreated, FName, TabId, UCommonButtonLegacy*, TabButton);
/** Delegate broadcast when a tab is being removed. Allows clean ups after destruction. */
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTabButtonRemoved, FName, TabId, UCommonButtonLegacy*, TabButton);

public:
	/** Broadcasts when a new tab is created. */
	UPROPERTY(BlueprintAssignable, Category="TabList")
	FOnTabButtonCreated OnTabButtonCreated;

	/** Broadcasts when a new tab is created. */
	UPROPERTY(BlueprintAssignable, Category="TabList")
	FOnTabButtonRemoved OnTabButtonRemoved;

protected:
	/** Returns the tab button matching the ID, if found */
	UFUNCTION(BlueprintCallable, Category="TabList", meta=(BlueprintProtected="true"))
	UCommonButtonLegacy* GetTabButtonByID(FName TabNameID);

	/** Legacy codebases will be overiding w.r.t CommonButton, provide an interface and call any overrides they might have. */
	UFUNCTION(BlueprintNativeEvent, Category="TabList", meta=(BlueprintProtected="true"))
	void HandleTabCreated(FName TabNameID, UCommonButtonLegacy* TabButton);

	UFUNCTION(BlueprintNativeEvent, Category="TabList", meta=(BlueprintProtected="true"))
	void HandleTabRemoved(FName TabNameID, UCommonButtonLegacy* TabButton);

private:
	UFUNCTION()
	void HandleOnTabButtonCreated(FName TabId, UCommonButtonBase* TabButton);

	UFUNCTION()
	void HandleOnTabButtonRemoved(FName TabId, UCommonButtonBase* TabButton);

};

