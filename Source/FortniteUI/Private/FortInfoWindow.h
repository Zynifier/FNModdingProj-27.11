// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortInfoWindow.generated.h"

class UCommonListView;
class UObject;
class UWidget;

UCLASS(meta=(DisableNativeTick))
class UFortInfoWindow : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="UFortInfoWindow")
	UWidget* GetListWidget(UObject* Item);

	UPROPERTY(BlueprintReadOnly, Export, Category="UFortInfoWindow", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonListView> InfoEntries;

};

