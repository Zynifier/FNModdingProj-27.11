// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UserGeneratedContentLocalization.h"
#include "ValkyrieProjectDescriptorEnums.h"
#include "ValkyrieProjectSettingsEditorViewModel.generated.h"

UCLASS()
class UValkyrieProjectSettingsEditorViewModel : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="General")
	FString Title;

	UPROPERTY(EditAnywhere, Category="General", meta=(MultiLine="TRUE"))
	FString Description;

	UPROPERTY()
	bool bShowVersePath;

	UPROPERTY(EditAnywhere, Category="General", meta=(EditCondition="bShowVersePath", EditConditionHides, HideEditConditionToggle, NoResetToDefault))
	FString VersePath;

	UPROPERTY(EditAnywhere, Category="General")
	EValkyrieProjectKind Kind;

	UPROPERTY(EditAnywhere, Category="General", meta=(DisplayName="Documentation URL"))
	FString DocsUrl;

	UPROPERTY(EditAnywhere, Category="Localization", meta=(DisplayName="Localization Settings", ShowOnlyInnerProperties))
	FUserGeneratedContentLocalizationDescriptor UGCLocDescriptor;

};

