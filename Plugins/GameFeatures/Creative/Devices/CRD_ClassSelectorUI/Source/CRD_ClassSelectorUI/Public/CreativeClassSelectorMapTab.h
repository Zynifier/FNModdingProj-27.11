// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Athena/AthenaMapScreenContainerTabInterface.h"
#include "CreativeClassSelectorMapTab.generated.h"

class UCreativeClassSelector;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UCreativeClassSelectorMapTab : public UCommonActivatableWidget, public IAthenaMapScreenContainerTabInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetTabName(const FText& TabName);

	UPROPERTY(EditAnywhere, Category="Fullscreen Map")
	FAthenaMapScreenContainerTabInfo MapTabInfo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="CreativeClassSelectorMapTab", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCreativeClassSelector> CreativeClassSelector;

};

