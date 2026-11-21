// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortTouchInteractionButton.generated.h"

class AActor;
class UFortMarkerDetailsTable;
class UImage;
class UTexture2D;
class UWidgetAnimation;

USTRUCT(BlueprintType)
struct FTouchInteractionIconOverride
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="TouchInteractionIconOverride")
	TSoftObjectPtr<UTexture2D> IconOverride;

	UPROPERTY(EditDefaultsOnly, Category="TouchInteractionIconOverride")
	float IconScale;

};

UCLASS(meta=(DisableNativeTick))
class UFortTouchInteractionButton : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnInteractionFocusChanged(bool bNewFocused);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTouchInteractionButton", meta=(BlueprintProtected="true"))
	FName MIDParam_Icon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTouchInteractionButton", meta=(BlueprintProtected="true"))
	FName MIDParam_IconScale;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTouchInteractionButton", meta=(BlueprintProtected="true"))
	FName MIDParam_Tint;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTouchInteractionButton", meta=(BlueprintProtected="true"))
	FName MIDParam_Duration;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTouchInteractionButton", meta=(BlueprintProtected="true"))
	FName MIDParam_StartTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTouchInteractionButton", meta=(BlueprintProtected="true"))
	FName MIDParam_TimerOpacity;

	UPROPERTY(BlueprintReadOnly, Category="FortTouchInteractionButton")
	bool bInteractionFocused;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortTouchInteractionButton", meta=(AllowPrivateAccess="TRUE", BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> Anim_RadialProgress;

private:
	UPROPERTY(Transient)
	TSoftObjectPtr<UTexture2D> PendingIcon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTouchInteractionButton", meta=(AllowPrivateAccess="TRUE"))
	TSoftObjectPtr<UTexture2D> DefaultIcon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTouchInteractionButton", meta=(AllowPrivateAccess="TRUE"))
	TMap<TSoftObjectPtr<UTexture2D>, FTouchInteractionIconOverride> IconOverrides;

	UPROPERTY(EditDefaultsOnly, Category="FortTouchInteractionButton")
	TObjectPtr<UFortMarkerDetailsTable> DetailsTable;

	UPROPERTY(EditDefaultsOnly, Category="FortTouchInteractionButton")
	float DefaultIconScale;

	UPROPERTY(EditDefaultsOnly, Category="FortTouchInteractionButton")
	float PickupIconScale;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortTouchInteractionButton", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Icon;

	UPROPERTY(Transient)
	TObjectPtr<AActor> TrackedActor;

};

