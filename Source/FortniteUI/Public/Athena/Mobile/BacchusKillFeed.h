// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Athena/Mobile/BacchusHUDElement.h"
#include "Athena/SlottedWidgets/FortPrioritizedWidgetInterface.h"
#include "Athena/SlottedWidgets/PrioritizedWidgetTypes.h"
#include "BacchusKillFeed.generated.h"

class UImage;
class USizeBox;

UCLASS(meta=(DisableNativeTick))
class UBacchusKillFeed : public UBacchusHUDElement, public IFortPrioritizedWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="UI")
	void SetActiveNumberOfLines(float numberOfLines);

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Prioritization", meta=(DisplayName="On Become Active"))
	void K2_OnBecomeActive();

	UFUNCTION(BlueprintImplementableEvent, Category="Prioritization", meta=(DisplayName="On Become Inactive"))
	void K2_OnBecomeInactive();

	UFUNCTION(BlueprintImplementableEvent, Category="Prioritization")
	void OnStompedByOtherWidget();

	UFUNCTION(BlueprintImplementableEvent, Category="Prioritization")
	void OnStompFailed();

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> MainSizeBox;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="Touch")
	TSoftObjectPtr<UImage> FireImageRef;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Touch")
	FVector2D FireImageAbsoluteOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Touch")
	FText ShowAllTimeTimePropertyName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	int32 NumberOfActiveLines;

	UPROPERTY(EditAnywhere, Category="Widget Priority")
	FFortPrioritizedWidgetData PrioritizationData;

private:
	UPROPERTY(EditAnywhere, Category="Custom Properties", meta=(Categories="HUDLayout.Property"))
	FGameplayTag NumberOfKillfeedLinesTag;

};

