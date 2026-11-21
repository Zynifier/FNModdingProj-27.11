// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortConsoleProfileWidget.generated.h"

class UTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortConsoleProfileWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortConsoleProfileWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_Prefix;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_DisplayName;

};

