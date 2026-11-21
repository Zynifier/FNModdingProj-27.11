// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "FortControllerActionsMenuEntry.generated.h"

class URichTextBlock;

UCLASS(Abstract)
class UFortControllerActionsMenuEntry : public UCommonButtonLegacy
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortControllerActionsMenuEntry", meta=(AllowPrivateAccess="TRUE", BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<URichTextBlock> Text_Action;

};

