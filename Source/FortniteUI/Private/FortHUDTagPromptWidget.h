// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/SlottedWidgets/FortPrioritizedWidgetInterface.h"
#include "Athena/SlottedWidgets/PrioritizedWidgetTypes.h"
#include "FortHUDElementWidget.h"
#include "FortHUDTagPromptTagMapping.h"
#include "FortHUDTagPromptWidget.generated.h"

class UFortHUDTagPromptTagMapping;
class UOverlay;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnOpenOrClosed, bool, bNewlyOpened);

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortHUDTagPromptContainerWidget : public UFortHUDElementWidget, public IFortPrioritizedWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void CloseWidget();

	UFUNCTION()
	void OnWidgetBaseOpenedOrClosed(bool bNewlyOpened);

	UFUNCTION()
	void OpenWidget(const FFortHUDTagPromptData& PrompData);

	UFUNCTION()
	void RequestPromptDataActivation(const FFortHUDTagPromptData& PromptData, const FGameplayTag& Tag);

	UPROPERTY(EditDefaultsOnly, Category="Tag Mapping Data")
	TObjectPtr<UFortHUDTagPromptTagMapping> TagMappingData;

	UPROPERTY(EditDefaultsOnly, Category="Cooldown")
	float CooldownTime;

	UPROPERTY(BlueprintAssignable, Category="HUD")
	FOnOpenOrClosed OnOpenedOrClosed;

	UPROPERTY()
	TMap<FGameplayTag, float> TagToTimeMap;

	UPROPERTY()
	FFortHUDTagPromptData PromptDataToShow;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortHUDTagPromptContainerWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> OverlayWidget;

	UPROPERTY(EditAnywhere, Category="Widget Priority")
	FFortPrioritizedWidgetData PrioritizationData;

};

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortHUDTagPromptWidgetBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void CloseWidget();

	UFUNCTION(BlueprintNativeEvent)
	void OpenWidget(const FFortHUDTagPromptData& PrompData);

	UPROPERTY()
	FOnOpenOrClosed OnOpenedOrClosed;

};

