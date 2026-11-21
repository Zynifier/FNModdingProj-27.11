// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPlayerSurveyAnalyticsData.generated.h"

USTRUCT()
struct FFortPlayerSurveyAnalyticsResponse
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint32 InitialOrder;

	UPROPERTY()
	FString ResponseTextID;

	UPROPERTY()
	FString ResponseTextLocalized;

	UPROPERTY()
	FString Selection;

};

USTRUCT()
struct FFortPlayerSurveyAnalyticsQuestion
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint32 InitialOrder;

	UPROPERTY()
	FString QuestionTextID;

	UPROPERTY()
	FString QuestionTextLocalized;

	UPROPERTY()
	FString QuestionType;

	UPROPERTY()
	TArray<FFortPlayerSurveyAnalyticsResponse> Responses;

	UPROPERTY()
	uint32 TimeTaken;

	UPROPERTY()
	bool bAnswered;

};

USTRUCT()
struct FFortPlayerSurveyAnalyticsTextReplacementEvaluation
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString TextReplacementTag;

	UPROPERTY()
	FString TextReplacementValueID;

	UPROPERTY()
	FString TextReplacementValueLocalized;

};

USTRUCT()
struct FFortPlayerSurveyAnalyticsData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString SurveyID;

	UPROPERTY()
	TArray<FFortPlayerSurveyAnalyticsQuestion> Questions;

	UPROPERTY()
	TArray<FFortPlayerSurveyAnalyticsTextReplacementEvaluation> TextReplacementEvaluations;

	UPROPERTY()
	FString PreviousMatchPlaylist;

	UPROPERTY()
	FString PreviousMatchGameSessionID;

};

