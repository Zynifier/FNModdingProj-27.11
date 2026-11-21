// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"
#include "FortTypes.h"
#include "FortItemView.generated.h"

class UCommonActivatableWidget;
class USceneComponent;

UCLASS(MinimalAPI, BlueprintType)
class UFortItemView : public UObject
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUserInputChangedView);

public:
	UFUNCTION(BlueprintPure, Category="Item View")
	FFortItemViewSettings GetSettings() const;

	UFUNCTION(BlueprintCallable, Category="Item View")
	void RegisterInputActions();

	UFUNCTION(BlueprintCallable, Category="Item View")
	void RestoreInitialTransform(bool bKeepCurrentRotation = false);

	UFUNCTION(BlueprintCallable, Category="Item View")
	void SetOwningWidget(UCommonActivatableWidget* Widget);

	UFUNCTION(BlueprintCallable, Category="Item View")
	void SetSceneComponentToAffect(USceneComponent* Component);

	UFUNCTION(BlueprintCallable, Category="Item View")
	void SetSettings(const FFortItemViewSettings& Settings);

	UFUNCTION(BlueprintCallable, Category="Item View")
	void UnregisterInputActions();

	UPROPERTY(EditDefaultsOnly, Category="FortItemView", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle UnifiedSupportsCameraControlInputAction;

	UPROPERTY(EditDefaultsOnly, Category="FortItemView", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle UnifiedZoomInputAction;

	UPROPERTY(EditDefaultsOnly, Category="FortItemView", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ZoomOutInputAction;

	UPROPERTY(EditDefaultsOnly, Category="FortItemView", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ZoomInInputAction;

	UPROPERTY(EditDefaultsOnly, Category="FortItemView", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle RotateInputAction;

	UPROPERTY(BlueprintAssignable)
	FOnUserInputChangedView OnItemRotationChanged;

	UPROPERTY(BlueprintAssignable)
	FOnUserInputChangedView OnItemZoomLevelChanged;

private:
	UPROPERTY()
	TArray<FDataTableRowHandle> RegisteredInputActions;

};

