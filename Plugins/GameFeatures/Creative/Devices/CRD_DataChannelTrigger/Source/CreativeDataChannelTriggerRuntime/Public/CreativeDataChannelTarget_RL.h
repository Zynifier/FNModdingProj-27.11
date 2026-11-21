// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CreativeDataChannelTypes.h"
#include "ElectraDataChannelTarget.h"
#include "CreativeDataChannelTarget_RL.generated.h"

UCLASS(Config=Creative, BlueprintType, Blueprintable, ClassGroup=("Creative"))
class CREATIVEDATACHANNELTRIGGERRUNTIME_API ACreativeDataChannelTargetRL : public AElectraDataChannelTarget
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnRep_BallCoords();

	UFUNCTION()
	void OnRep_FinaleState();

	UFUNCTION()
	void OnRep_MatchState();

	UFUNCTION()
	void OnRep_MediaStart();

	UFUNCTION()
	void OnRep_MediaStop();

	UFUNCTION()
	void OnRep_Overtime();

	UFUNCTION()
	void OnRep_PlayerBoost();

	UFUNCTION()
	void OnRep_PlayerBoostCollected();

	UFUNCTION()
	void OnRep_PlayerCoords();

	UFUNCTION()
	void OnRep_PlayerNames();

	UFUNCTION()
	void OnRep_ScoreboardBestOf();

	UFUNCTION()
	void OnRep_ScoreboardTimeLeft();

	UFUNCTION()
	void OnRep_ScoreTeam();

	UFUNCTION()
	void OnRep_ScoreTotal();

	UFUNCTION()
	void OnRep_SeriesState();

	UFUNCTION()
	void OnRep_TeamNames();

	UFUNCTION()
	void OnRep_VersionByte();

	UFUNCTION(BlueprintCallable)
	void ReportServerStateStreamError(const FString& Error, const FString& UID = TEXT(""), const FString& URL = TEXT(""));

	UPROPERTY(BlueprintReadWrite, Category="CreativeDataChannelTargetRL")
	int32 VersionByte;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetRL")
	FCDCInt VersionByteTracker;

	UPROPERTY(BlueprintAssignable)
	FCDCEventIntRep VersionByteEvent;

	UPROPERTY(BlueprintReadWrite, Category="CreativeDataChannelTargetRL")
	int32 ScoreTeam;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetRL")
	FCDCString ScoreTeamTracker;

	UPROPERTY(BlueprintAssignable)
	FCDCEventStringRep ScoreTeamEvent;

	UPROPERTY(BlueprintReadWrite, Category="CreativeDataChannelTargetRL")
	FString ScoreTotal;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetRL")
	FCDCStringIntMap ScoreTotalTracker;

	UPROPERTY(BlueprintAssignable)
	FCDCEventIntMapRep ScoreTotalEvent;

	UPROPERTY(BlueprintReadWrite, Category="CreativeDataChannelTargetRL")
	int64 ScoreboardTimeLeft;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetRL")
	FCDCLargeInt ScoreboardTimeLeftTracker;

	UPROPERTY(BlueprintAssignable)
	FCDCEventLargeIntRep ScoreboardTimeLeftEvent;

	UPROPERTY(BlueprintReadWrite, Category="CreativeDataChannelTargetRL")
	FString ScoreboardBestOf;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetRL")
	FCDCStringIntMap ScoreboardBestOfTracker;

	UPROPERTY(BlueprintAssignable)
	FCDCEventIntMapRep ScoreboardBestOfEvent;

	UPROPERTY(BlueprintReadWrite, Category="CreativeDataChannelTargetRL")
	int32 Overtime;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetRL")
	FCDCInt OvertimeTracker;

	UPROPERTY(BlueprintAssignable)
	FCDCEventIntRep OvertimeEvent;

	UPROPERTY(BlueprintReadWrite, Category="CreativeDataChannelTargetRL")
	FString TeamNames;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetRL")
	FCDCStringArray TeamNamesTracker;

	UPROPERTY(BlueprintAssignable)
	FCDCStringArrayRep TeamNamesEvent;

	UPROPERTY(BlueprintReadWrite, Category="CreativeDataChannelTargetRL")
	FString PlayerNames;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetRL")
	FCDCStringArray PlayerNamesTracker;

	UPROPERTY(BlueprintAssignable)
	FCDCStringArrayRep PlayerNamesEvent;

	UPROPERTY(BlueprintReadWrite, Category="CreativeDataChannelTargetRL")
	FString PlayerBoost;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetRL")
	FCDCStringIntMap PlayerBoostTracker;

	UPROPERTY(BlueprintAssignable)
	FCDCEventIntMapRep PlayerBoostEvent;

	UPROPERTY(BlueprintReadWrite, Category="CreativeDataChannelTargetRL")
	FString PlayerBoostCollected;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetRL")
	FCDCStringStringMap PlayerBoostCollectedTracker;

	UPROPERTY(BlueprintAssignable)
	FCDCEventStringMapRep PlayerBoostCollectedEvent;

	UPROPERTY(BlueprintReadWrite, Category="CreativeDataChannelTargetRL")
	FString PlayerCoords;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetRL")
	FCDCStringFloatArrayMap PlayerCoordsTracker;

	UPROPERTY(BlueprintAssignable)
	FCDCEventFloatArrayMapRep PlayerCoordsEvent;

	UPROPERTY(BlueprintReadWrite, Category="CreativeDataChannelTargetRL")
	FString BallCoords;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetRL")
	FCDCFloatArray BallCoordsTracker;

	UPROPERTY(BlueprintAssignable)
	FCDCEventFloatArrayRep BallCoordsEvent;

	UPROPERTY(BlueprintReadWrite, Category="CreativeDataChannelTargetRL")
	FString MediaStart;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetRL")
	FCDCStringStringMap MediaStartTracker;

	UPROPERTY(BlueprintAssignable)
	FCDCEventStringMapRep MediaStartEvent;

	UPROPERTY(BlueprintReadWrite, Category="CreativeDataChannelTargetRL")
	int32 MediaStop;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetRL")
	FCDCInt MediaStopTracker;

	UPROPERTY(BlueprintAssignable)
	FCDCEventIntRep MediaStopEvent;

	UPROPERTY(BlueprintReadWrite, Category="CreativeDataChannelTargetRL")
	int32 SeriesState;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetRL")
	FCDCInt SeriesStateTracker;

	UPROPERTY(BlueprintAssignable)
	FCDCEventIntRep SeriesStateEvent;

	UPROPERTY(BlueprintReadWrite, Category="CreativeDataChannelTargetRL")
	int32 MatchState;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetRL")
	FCDCInt MatchStateTracker;

	UPROPERTY(BlueprintAssignable)
	FCDCEventIntRep MatchStateEvent;

	UPROPERTY(BlueprintReadWrite, Category="CreativeDataChannelTargetRL")
	int32 FinaleState;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetRL")
	FCDCInt FinaleStateTracker;

	UPROPERTY(BlueprintAssignable)
	FCDCEventIntRep FinaleStateEvent;

};

