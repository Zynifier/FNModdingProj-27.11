// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortBattlePassPrerequisiteHeader.generated.h"

class UTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortBattlePassPrerequisiteHeader : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortBattlePassPrerequisiteHeader(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_Prerequisite;

};

