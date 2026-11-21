// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/FortCheatManager.h"
#include "FortPlayerSurveyCheatManager.generated.h"

UCLASS()
class FORTNITEUI_API UFortPlayerSurveyCheatManager : public UChildCheatManager
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void ListActivePlaylistNames(bool bWithCMSModification = false);

	UFUNCTION(Exec)
	void ListCMSPlayerSurveys();

	UFUNCTION(Exec)
	void ListDisabledPlayerSurveys();

	UFUNCTION(Exec)
	void ListItemsParsedFromPlaylistLootPools(bool bOnlyListWeapons = false, bool bWithCMSModification = false);

	UFUNCTION(Exec)
	void TestCMSPlayerSurvey(const FString& SurveyID);

	UFUNCTION(Exec)
	void TriggerCMSPlayerSurvey(const FString& SurveyID = TEXT(""));

};

