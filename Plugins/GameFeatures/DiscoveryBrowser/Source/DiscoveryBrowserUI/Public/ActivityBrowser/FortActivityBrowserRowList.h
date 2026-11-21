// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActivityBrowser/FortActivityBrowserRow.h"
#include "FortActivityBrowserRowList.generated.h"

class UCommonButtonBase;
class UFortActivityListView;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortActivityBrowserRowList : public UFortActivityBrowserRow
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnQueryStatusChanged(bool bIsActive);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityBrowserRowList", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortActivityListView> ListView_Activities;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityBrowserRowList", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_PageLeft;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityBrowserRowList", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_PageRight;

};

