// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortSettingsPreviewActionUnbind.generated.h"

class UCommonTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortSettingsPreviewActionUnbind : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortSettingsPreviewActionUnbind(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortSettingsPreviewActionUnbind", meta=(AllowPrivateAccess="TRUE", BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Action;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSettingsPreviewActionUnbind", meta=(AllowPrivateAccess="TRUE", BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PrimaryKey;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSettingsPreviewActionUnbind", meta=(AllowPrivateAccess="TRUE", BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SecondaryKey;

};

