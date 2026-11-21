// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortCreativeContentBrowserTabPanelBase.generated.h"

class UFortCreativeContentBrowserTabPanelBase;
enum class EFortCreativeItemType : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSelectionChangedDelegate, UFortCreativeContentBrowserTabPanelBase*, TabPanel);

UCLASS(meta=(DisableNativeTick))
class FORTNITEUI_API UFortCreativeContentBrowserTabPanelBase : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	virtual EFortCreativeItemType GetItemType();

	UFUNCTION(BlueprintCallable)
	virtual int32 GetSelectedItemIndex();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SelectTab();

	UPROPERTY(BlueprintAssignable)
	FOnSelectionChangedDelegate OnSelectionChanged;

private:
	UPROPERTY(BlueprintReadOnly, Category="FortCreativeContentBrowserTabPanelBase", meta=(AllowPrivateAccess="true"))
	FName TabName;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeContentBrowserTabPanelBase", meta=(AllowPrivateAccess="true"))
	FText TabLabel;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeContentBrowserTabPanelBase", meta=(AllowPrivateAccess="true"))
	TArray<FName> LastFilters;

};

