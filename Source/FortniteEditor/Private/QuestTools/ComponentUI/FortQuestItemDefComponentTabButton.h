// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "FortQuestItemDefComponentTabButton.generated.h"

class UCommonTextBlock;
class UObject;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortQuestItemDefComponentTabButton : public UCommonButtonBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestItemDefComponentTabButton", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ComponentName;

private:
	UPROPERTY()
	UClass* ComponentClass;

};

