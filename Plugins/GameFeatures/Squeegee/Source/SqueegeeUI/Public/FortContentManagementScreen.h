// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Settings/FortPinScreen.h"
#include "FortContentManagementScreen.generated.h"

class UCommonButtonBase;
class UFortContentManagementDetails;
class UFortContentManagementList;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class SQUEEGEEUI_API UFortContentManagementScreen : public UFortPinScreen
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void ExitScreen();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortContentManagementScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortContentManagementList> ContentManagementList;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortContentManagementDetails> ContentManagementDetails;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CloseTouch;

};

