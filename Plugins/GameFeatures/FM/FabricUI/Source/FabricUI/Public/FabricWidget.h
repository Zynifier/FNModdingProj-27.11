// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FabricWidget.generated.h"

class UFabricGridStyle;
class UFabricInteractableViewModel;

UCLASS(Abstract, BlueprintType, Blueprintable, ClassGroup=("UI"), meta=(Category="Fabric UI", DisableNativeTick))
class FABRICUI_API UFabricWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	UFabricInteractableViewModel* GetFabricViewModel() const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FabricWidget")
	TSubclassOf<UFabricGridStyle> GridStyle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FabricWidget")
	TSubclassOf<UFabricInteractableViewModel> ViewModelClass;

};

