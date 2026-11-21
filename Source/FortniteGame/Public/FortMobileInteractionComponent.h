// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "FortMobileInteractionComponent.generated.h"

class UMaterialInstanceDynamic;
enum class EMobileInteractionIconTypes : uint8;

UCLASS(HideCategories=("Object", "Activation", "Components|Activation", "Trigger"))
class UFortMobileInteractionComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Interaction")
	bool IsAvailable() const;

	UFUNCTION(BlueprintCallable, Category="Interaction")
	void SetCameraPush(float Offset);

	UFUNCTION(BlueprintCallable, Category="Interaction")
	void SetExtents(FVector Extents);

	UFUNCTION(BlueprintCallable, Category="Interaction")
	void SetIcon(EMobileInteractionIconTypes IconType);

	UFUNCTION(BlueprintCallable, Category="Interaction")
	void SetRarityColor(FLinearColor InColor);

	UFUNCTION(BlueprintCallable, Category="Interaction")
	void SetUpdateLocationOnTick(bool bShouldUpdate);

	UFUNCTION(BlueprintCallable, Category="Interaction")
	void SetVisibleStartTime();

	UFUNCTION(BlueprintCallable, Category="Interaction")
	void StartRadialTimer(float Duration);

	UFUNCTION(BlueprintCallable, Category="Interaction")
	void StopRadialTimer();

protected:
	UFUNCTION(BlueprintCallable, Category="Interaction")
	void SetRadialDuration(float Duration);

	UFUNCTION(BlueprintCallable, Category="Interaction")
	void SetRadialOpacity(float Opacity);

	UFUNCTION(BlueprintCallable, Category="Interaction")
	void SetRadialStartTime(float StartTime);

	UFUNCTION(BlueprintCallable, Category="Interaction")
	void TickLocation(float DeltaTime);

	UPROPERTY()
	TObjectPtr<UMaterialInstanceDynamic> IconMID;

};

