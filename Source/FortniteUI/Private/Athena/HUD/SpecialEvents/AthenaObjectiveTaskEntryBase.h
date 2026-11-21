// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Math/Color.h"
#include "AthenaObjectiveTaskEntryBase.generated.h"

class UFortRichTextBlockKeybind;
class UOverlay;
enum class EFortEarnedSubRewardType : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaObjectiveTaskEntryBase : public UUserWidget
{
	GENERATED_BODY()

public:
	UAthenaObjectiveTaskEntryBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnNewlyCompleted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnObjectiveRewardSet(const int32 RewardQuantity, const EFortEarnedSubRewardType RewardType);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateOptionalObjectiveProgress(const FText& Text);

	UFUNCTION(BlueprintImplementableEvent)
	void OverridePrimaryColor(const bool bShouldOverride, const FLinearColor& DesiredColor);

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaObjectiveTaskEntryBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortRichTextBlockKeybind> Text_ObjectiveDescriptionText;

	UPROPERTY(BlueprintReadOnly, Category="AthenaObjectiveTaskEntryBase")
	bool bCompleted;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaObjectiveTaskEntryBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_ProgressText;

};

