// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorConfigBase.h"
#include "ValkyrieEditorPermissionSettingsTypes.h"
#include "ValkyriePropertyPermissionList.h"
#include "ValkyrieEditorPermissionSettings.generated.h"

UCLASS(meta=(EditorConfig="ValkyrieEditorPermissions"))
class VALKYRIEEDITOR_API UValkyrieEditorPermissionSettings : public UEditorConfigBase
{
	GENERATED_BODY()

public:
	UPROPERTY(meta=(EditorConfig))
	FValkyrieEditorPermissionSettings_Project ValkyrieProjectSettings;

	UPROPERTY(meta=(EditorConfig))
	FValkyrieEditorPermissionSettings_Blueprints ValkyrieBlueprintsSettings;

	UPROPERTY(meta=(EditorConfig))
	FValkyrieEditorPermissionSettings_Animation ValkyrieAnimationSettings;

	UPROPERTY(meta=(EditorConfig))
	FValkyrieEditorPermissionSettings_Audio ValkyrieAudioSettings;

	UPROPERTY(meta=(EditorConfig))
	FValkyrieEditorPermissionSettings_UMG ValkyrieUMGSettings;

	UPROPERTY(meta=(EditorConfig))
	FValkyrieEditorPermissionSettings_EditorUtility ValkyrieEditorUtilitySettings;

	UPROPERTY(meta=(EditorConfig))
	FValkyrieEditorPermissionSettings_Editor ValkyrieEditorSettings;

	UPROPERTY(EditAnywhere, Category="Properties", meta=(AllowAbstract, EditorConfig))
	TArray<FValkyrieClassPropertyPermissionList> PropertyEditorClassPermissionList;

	UPROPERTY(EditAnywhere, Category="Properties", meta=(AllowAbstract, EditorConfig))
	TArray<FValkyrieStructPropertyPermissionList> PropertyEditorStructPermissionList;

	UPROPERTY(EditAnywhere, Category="Properties", meta=(AllowAbstract, EditorConfig))
	TArray<FValkyrieClassPropertyPermissionList> PropertySaveClassPermissionList;

	UPROPERTY(EditAnywhere, Category="Properties", meta=(AllowAbstract, EditorConfig))
	TArray<FValkyrieStructPropertyPermissionList> PropertySaveStructPermissionList;

	UPROPERTY(EditAnywhere, Category="Properties", meta=(AllowAbstract, EditorConfig))
	TArray<FValkyrieClassPropertyPermissionList> HiddenPropertyClassPermissionList;

	UPROPERTY(EditAnywhere, Category="Properties", meta=(AllowAbstract, EditorConfig))
	TArray<FValkyrieStructPropertyPermissionList> HiddenPropertyStructPermissionList;

};

