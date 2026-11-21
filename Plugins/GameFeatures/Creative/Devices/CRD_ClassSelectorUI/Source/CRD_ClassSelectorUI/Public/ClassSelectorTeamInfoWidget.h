// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ClassSelectorTeamInfoWidget.generated.h"

class UCommonTextBlock;

UCLASS()
class UClassSelectorTeamInfoWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UClassSelectorTeamInfoWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TeamName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TeamCountText;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TeamDescription;

};

