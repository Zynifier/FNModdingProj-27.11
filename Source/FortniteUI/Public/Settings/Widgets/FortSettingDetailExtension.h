// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortSettingDetailExtension.generated.h"

class UFortSetting;

UCLASS(Abstract, MinimalAPI, meta=(Category="Settings", DisableNativeTick))
class UFortSettingDetailExtension : public UUserWidget
{
	GENERATED_BODY()

public:
	FORTNITEUI_API UFortSettingDetailExtension(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintPure)
	FORTNITEUI_API const FText GetOptionsDisabledText(const TArray<FText>& Reasons) const;

	UFUNCTION(BlueprintCallable)
	FORTNITEUI_API bool UseSplitDisabledOptionsVisual();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnSettingAssigned(UFortSetting* InSetting);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnSettingValueChanged(UFortSetting* InSetting);

	UPROPERTY(Transient)
	TObjectPtr<UFortSetting> Setting;

};

