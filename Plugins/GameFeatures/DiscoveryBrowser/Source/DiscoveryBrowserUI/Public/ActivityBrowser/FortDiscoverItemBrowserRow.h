// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActivityBrowser/FortActivityBrowserRow.h"
#include "FortDiscoverItemBrowserRow.generated.h"

class UCommonButtonBase;
class UFortDiscoverItemListView;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortDiscoverItemBrowserRow : public UFortActivityBrowserRow
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortDiscoverItemBrowserRow", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortDiscoverItemListView> ListView_Tiles;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortDiscoverItemBrowserRow", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_PageLeft;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortDiscoverItemBrowserRow", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_PageRight;

};

