// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "FortResourceFeed.generated.h"

class AActor;
class ABuildingSMActor;
class AFortVolume;
class UFortItem;
class UFortItemDefinition;
class UFortSimpleWidgetAnimationsPanel;
class UFortWorldItem;
class UImage;
class UTextBlock;
class UWidget;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortResourceFeed : public UFortHUDElementWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Anmimations")
	float ResourceGainedTime;

protected:
	UFUNCTION(BlueprintCallable, Category="Resource Feed")
	void HandleFadeOutFinished();

	UFUNCTION(BlueprintCallable, Category="Resource Feed")
	void HandleResourceGainedFinished();

	UFUNCTION(BlueprintCallable, Category="Resource Feed")
	void HandleWeakpointHitFinished();

	UFUNCTION(BlueprintImplementableEvent, Category="Resource Feed")
	void OnFadeOut();

	UFUNCTION(BlueprintImplementableEvent, Category="Resource Feed")
	void OnResourceGained();

	UFUNCTION(BlueprintImplementableEvent, Category="Resource Feed")
	void OnWeakpointHit();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortResourceFeed", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_ResourceCount;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortResourceFeed", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_ResourceGained;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortResourceFeed", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_Glow;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortResourceFeed", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSimpleWidgetAnimationsPanel> Panel_Animations;

private:
	UFUNCTION()
	void HandleDamagedResourceActor(AActor* InActor, UFortItem* InItem, bool bDestroyed, bool bJustHitWeakspot);

	UFUNCTION()
	void HandleDamagedResourceBuilding(ABuildingSMActor* InBuildingSMActor, UFortItem* InItem, bool bDestroyed, bool bJustHitWeakspot);

	UFUNCTION()
	void HandleGamePhaseChanged();

	UFUNCTION()
	void HandleItemPickedUp(UFortWorldItem* WorldItem, int32 Count);

	UFUNCTION()
	void HandlePlayerVolumeChanged(AFortVolume* Volume);

	UFUNCTION()
	bool HandleTimedOut(float InDeltaTime);

	UPROPERTY()
	TObjectPtr<UFortItemDefinition> CurrentItemDefinition;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_ResourceIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_ResourceCount;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_ResourceGained;

};

