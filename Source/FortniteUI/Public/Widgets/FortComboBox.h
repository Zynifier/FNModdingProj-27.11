// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortComboBox.generated.h"

class UComboBoxString;

UCLASS(meta=(DisableNativeTick))
class FORTNITEUI_API UFortComboBox : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, Export, Category="FortComboBox", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UComboBoxString> ComboBox;

};

