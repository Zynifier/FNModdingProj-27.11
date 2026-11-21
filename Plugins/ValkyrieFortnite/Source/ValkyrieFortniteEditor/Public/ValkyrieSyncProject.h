// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "ValkyrieSyncProject.generated.h"

UENUM()
enum class EValkyrieSyncProjectOptions : uint8
{
	None = 0,
	AllowUpload = 1,
	// Useful to just run validation without continuing to upload and sync

	AllowClientUpdate = 2,
	// Only applicable if AllowUpload is set, will update connected clients

	ForceFullValidation = 4,
	// Run a full validation pass on all files, even if not dirty

	PassedLocalValidation = 8,
	// Set if local validation has already run and passed

	Default = 3,
};

UENUM()
enum class EValkyrieSyncProjectState : uint8
{
	Untracked = 0,
	Tracked = 1,
	Staging = 2,
	Uploading = 3,
	CreatingModuleVersions = 4,
	Failed = 5,
	UpToDate = 6,
};

UCLASS()
class VALKYRIEFORTNITEEDITOR_API UValkyrieSyncProjectManager : public UEditorSubsystem
{
	GENERATED_BODY()

};

