// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AssetRegistry/AssetData.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortReleaseVersion.h"
#include "FortReleaseVersionEditorLibrary.generated.h"

UCLASS()
class FORTNITEEDITOR_API UFortReleaseVersionEditorLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintCallable, Category="FortReleaseVersion")
	static bool EditorOnly_BuildFortReleaseVersionFromAssetData(const FAssetData& AssetData, FFortReleaseVersion& OutVersion);

	UFUNCTION(BlueprintCallable, Category="FortReleaseVersion")
	static bool EditorOnly_BuildFortReleaseVersionFromString(const FString& VersionString, FFortReleaseVersion& OutVersion);

	UFUNCTION(BlueprintCallable, Category="FortReleaseVersion")
	static bool EditorOnly_DoVersionSeasonsMatch(const FFortReleaseVersion& VersionA, const FFortReleaseVersion& VersionB);

	UFUNCTION(BlueprintCallable, Category="FortReleaseVersion")
	static FFortReleaseVersion EditorOnly_GetCurrentFortReleaseVersion();

	UFUNCTION(BlueprintCallable, Category="FortReleaseVersion")
	static FText EditorOnly_GetVersionDisplayTextForUIPurposes(const FFortReleaseVersion& Version);

	UFUNCTION(BlueprintCallable, Category="FortReleaseVersion")
	static int32 EditorOnly_GetVersionSeasonNumber(const FFortReleaseVersion& Version);

	UFUNCTION(BlueprintCallable, Category="FortReleaseVersion")
	static bool EditorOnly_IsVersionEqualTo(const FFortReleaseVersion& VersionA, const FFortReleaseVersion& VersionB);

	UFUNCTION(BlueprintCallable, Category="FortReleaseVersion")
	static bool EditorOnly_IsVersionGreaterThan(const FFortReleaseVersion& VersionA, const FFortReleaseVersion& VersionB);

	UFUNCTION(BlueprintCallable, Category="FortReleaseVersion")
	static bool EditorOnly_IsVersionLessThan(const FFortReleaseVersion& VersionA, const FFortReleaseVersion& VersionB);

};

