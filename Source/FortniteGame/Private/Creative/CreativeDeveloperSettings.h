// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "Online/FortPlaylistCuratedContent.h"
#include "CreativeDeveloperSettings.generated.h"

class AActor;

UCLASS(Config=EditorPerProjectUserSettings, meta=(DisplayName="Creative Developer Settings"))
class UCreativeDeveloperSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="Creative")
	TArray<FString> CuratedLinkCodes;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Config, Category="Creative")
	TMap<FString, FFortPlaylistCuratedContent> PlaylistCuratedContent;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Athena")
	FString PlaylistCuratedHub;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Config, Category="Creative")
	FString DirectLoadLinkCode;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="Creative")
	bool bUseCuratedCalendar;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="Creative")
	bool bGeneratePlaysetOnSave;
#endif

	UPROPERTY()
	TSoftClassPtr<AActor> PlaysetThumbnailEditorStage;

	UPROPERTY(EditAnywhere, Config, Category="Beta Permissions")
	TMap<FString, FString> ValidPermissionTags;

};

