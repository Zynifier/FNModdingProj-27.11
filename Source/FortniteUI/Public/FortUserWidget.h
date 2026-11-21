// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortClientEventInterface.h"
#include "FortUserWidget.generated.h"

UCLASS(ClassGroup=("UI"), meta=(Category="Fortnite UI", DisableNativeTick))
class FORTNITEUI_API UFortUserWidget : public UUserWidget, public IFortClientEventInterface
{
	GENERATED_BODY()

public:
	UFortUserWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortUserWidget")
	bool bConsumePointerInput;

};

