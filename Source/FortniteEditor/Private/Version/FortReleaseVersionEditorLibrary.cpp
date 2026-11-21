// Copyright Epic Games, Inc. All Rights Reserved.

#include "Version/FortReleaseVersionEditorLibrary.h"

bool UFortReleaseVersionEditorLibrary::EditorOnly_BuildFortReleaseVersionFromAssetData(const FAssetData& AssetData, FFortReleaseVersion& OutVersion)
{
	return false;
}

bool UFortReleaseVersionEditorLibrary::EditorOnly_BuildFortReleaseVersionFromString(const FString& VersionString, FFortReleaseVersion& OutVersion)
{
	return false;
}

bool UFortReleaseVersionEditorLibrary::EditorOnly_DoVersionSeasonsMatch(const FFortReleaseVersion& VersionA, const FFortReleaseVersion& VersionB)
{
	return false;
}

FFortReleaseVersion UFortReleaseVersionEditorLibrary::EditorOnly_GetCurrentFortReleaseVersion()
{
	return FFortReleaseVersion();
}

FText UFortReleaseVersionEditorLibrary::EditorOnly_GetVersionDisplayTextForUIPurposes(const FFortReleaseVersion& Version)
{
	return FText();
}

int32 UFortReleaseVersionEditorLibrary::EditorOnly_GetVersionSeasonNumber(const FFortReleaseVersion& Version)
{
	return int32();
}

bool UFortReleaseVersionEditorLibrary::EditorOnly_IsVersionEqualTo(const FFortReleaseVersion& VersionA, const FFortReleaseVersion& VersionB)
{
	return false;
}

bool UFortReleaseVersionEditorLibrary::EditorOnly_IsVersionGreaterThan(const FFortReleaseVersion& VersionA, const FFortReleaseVersion& VersionB)
{
	return false;
}

bool UFortReleaseVersionEditorLibrary::EditorOnly_IsVersionLessThan(const FFortReleaseVersion& VersionA, const FFortReleaseVersion& VersionB)
{
	return false;
}
