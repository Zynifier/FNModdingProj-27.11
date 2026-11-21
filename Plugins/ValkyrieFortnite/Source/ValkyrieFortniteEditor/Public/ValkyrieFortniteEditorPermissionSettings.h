// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ValkyrieEditorPermissionSettings.h"
#include "ValkyrieFortniteEditorPermissionSettings.generated.h"

UCLASS(meta=(EditorConfig="ValkyrieFortniteEditorPermissions"))
class VALKYRIEFORTNITEEDITOR_API UValkyrieFortniteEditorPermissionSettings : public UValkyrieEditorPermissionSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Editor", meta=(EditorConfig))
	bool bEnableAccessToLegacyContent;

	UPROPERTY(EditAnywhere, Category="Editor", meta=(EditorConfig))
	bool bEnableAccessToUnreleasedContent;

};

