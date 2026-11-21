// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "FortCreativeIslandPanel.generated.h"

class APlayerController;
class UInputComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSupportCreatorOLD);

UCLASS(Abstract)
class UFortCreativeIslandPanel : public UFortHUDElementWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Island Panel")
	FString GetSupportCode() const;

	UFUNCTION(BlueprintCallable, Category="Island Panel")
	void PopPanelInputComponent(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category="Island Panel")
	void PushPanelInputComponent(APlayerController* PlayerController);

	UPROPERTY(BlueprintAssignable, Category="Island Panel")
	FOnSupportCreatorOLD OnSupportCreator;

private:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> PanelInputComponent;

};

