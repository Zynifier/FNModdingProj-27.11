// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Core/FortInitializeFromObjectInterface.h"
#include "SpecialEventCursorWidget.generated.h"

class USpecialEventCursorPawnComponent;

UCLASS(meta=(DisableNativeTick))
class SPECIALEVENTGAMEPLAYUI_API USpecialEventCursorWidget : public UUserWidget, public IFortInitializeFromObjectInterface
{
	GENERATED_BODY()

public:
	USpecialEventCursorWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintPure)
	FGameplayTagContainer GetCursorModeTags() const;

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="OnCursorModeChanged"))
	void BP_OnCursorModeChanged(USpecialEventCursorPawnComponent* InCursorPawnComponent, const FGameplayTag& NewCursorModeTag, const FGameplayTag& OldCursorModeTag);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="OnDesiredVisibilityChanged"))
	void BP_OnDesiredVisibilityChanged(USpecialEventCursorPawnComponent* InCursorPawnComponent, const FGameplayTag& CursorModeTag, const bool bShouldBeVisible);

	UFUNCTION(BlueprintNativeEvent)
	void OnViewportLocationChanged(USpecialEventCursorPawnComponent* InCursorPawnComponent, const FVector2D& NormalizedLocation, const FVector2D& ViewportLocation);

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventCursorWidget")
	bool bAutomaticallyChangeVisibility;

	UPROPERTY(BlueprintReadOnly, Export, Category="SpecialEventCursorWidget", meta=(EditInline="true"))
	TObjectPtr<USpecialEventCursorPawnComponent> CursorPawnComponent;

private:
	UFUNCTION()
	void OnCursorModeChanged(USpecialEventCursorPawnComponent* InCursorPawnComponent, const FGameplayTag& NewCursorModeTag, const FGameplayTag& OldCursorModeTag);

	UFUNCTION()
	void OnDesiredVisibilityChanged(USpecialEventCursorPawnComponent* InCursorPawnComponent, const FGameplayTag& CursorModeTag, const bool bShouldBeVisible);

};

