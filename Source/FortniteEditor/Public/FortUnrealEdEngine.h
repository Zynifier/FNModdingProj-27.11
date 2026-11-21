// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Editor/UnrealEdEngine.h"
#include "FortUnrealEdEngine.generated.h"

class UEditorViewportFlashlight;
class UFortConversationEditorPlayback;

UCLASS()
class UFortUnrealEdEngine : public UUnrealEdEngine
{
	GENERATED_BODY()

private:
	UPROPERTY()
	int32 DelayedPieFramesLeft;

	UPROPERTY(Config)
	FString SourceControlStatusBranchConfig;

	UPROPERTY(Config)
	int32 MaxSourceControlStatusBranchConfigEntries;

	UPROPERTY(Config)
	TArray<FString> SourceControlStatusBranches;

	UPROPERTY(Config)
	bool bAutoSetSkelMeshLODsOnImport;

	UPROPERTY(Transient)
	TObjectPtr<UFortConversationEditorPlayback> ConversationPlaybackContext;

	UPROPERTY(Transient)
	TObjectPtr<UEditorViewportFlashlight> ViewportFlashlight;

};

