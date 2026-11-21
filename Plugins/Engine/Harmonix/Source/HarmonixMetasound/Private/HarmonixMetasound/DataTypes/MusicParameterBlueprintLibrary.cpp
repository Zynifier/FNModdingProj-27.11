// Copyright Epic Games, Inc. All Rights Reserved.

#include "HarmonixMetasound/DataTypes/MusicParameterBlueprintLibrary.h"

FMusicLoopConfiguration UMusicParameterBlueprintLibrary::GetMusicLoopConfiguration(UMetasoundParameterPack* Target, FName ParameterName, ESetParamResult& Result)
{
	return FMusicLoopConfiguration();
}

FMusicSeekRequest UMusicParameterBlueprintLibrary::GetMusicSeekRequest(UMetasoundParameterPack* Target, FName ParameterName, ESetParamResult& Result)
{
	return FMusicSeekRequest();
}

FMusicTimestamp UMusicParameterBlueprintLibrary::GetMusicTimestamp(UMetasoundParameterPack* Target, FName ParameterName, ESetParamResult& Result)
{
	return FMusicTimestamp();
}

bool UMusicParameterBlueprintLibrary::HasMusicLoopConfiguration(UMetasoundParameterPack* Target, FName Name)
{
	return false;
}

bool UMusicParameterBlueprintLibrary::HasMusicSeekRequest(UMetasoundParameterPack* Target, FName Name)
{
	return false;
}

bool UMusicParameterBlueprintLibrary::HasMusicTimestamp(UMetasoundParameterPack* Target, FName Name)
{
	return false;
}

void UMusicParameterBlueprintLibrary::SetMusicLoopConfiguration(UMetasoundParameterPack* Target, FName ParameterName, FMusicLoopConfiguration& Value, ESetParamResult& Result, bool OnlyIfExists)
{
}

void UMusicParameterBlueprintLibrary::SetMusicSeekRequest(UMetasoundParameterPack* Target, FName ParameterName, FMusicSeekRequest& Value, ESetParamResult& Result, bool OnlyIfExists)
{
}

void UMusicParameterBlueprintLibrary::SetMusicTimestamp(UMetasoundParameterPack* Target, FName ParameterName, FMusicTimestamp& Value, ESetParamResult& Result, bool OnlyIfExists)
{
}
