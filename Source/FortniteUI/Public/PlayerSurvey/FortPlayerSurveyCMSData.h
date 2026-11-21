// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "JsonObjectWrapper.h"
#include "PlayerSurvey/FortPlayerSurveyUtils.h"
#include "FortPlayerSurveyCMSData.generated.h"

USTRUCT()
struct FFortPlayerSurveyCMSCondition
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Type;

	UPROPERTY()
	FString Operation;

	UPROPERTY()
	FString ComparisonValue;

	UPROPERTY()
	TArray<FString> ConditionInfo;

	UPROPERTY()
	TArray<FJsonObjectWrapper> ChildConditions;

};

USTRUCT()
struct FFortPlayerSurveyCMSConditionGroup
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ConditionGroupID;

	UPROPERTY()
	TArray<FFortPlayerSurveyCMSCondition> Conditions;

};

USTRUCT()
struct FFortPlayerSurveyCMSCustomTextReplacement
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString TextReplacementTag;

	UPROPERTY()
	TArray<FFortPlayerSurveyLocalizableText> TextReplacementValues;

};

USTRUCT()
struct FFortPlayerSurveyCMSQuestion
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFortPlayerSurveyLocalizableText QuestionText;

	UPROPERTY()
	FString Type;

	UPROPERTY()
	uint32 NumberOfOptions;

	UPROPERTY()
	TArray<FFortPlayerSurveyLocalizableText> Responses;

	UPROPERTY()
	bool bRandomizeResponseOrder;

};

USTRUCT()
struct FFortPlayerSurveyCMSFrequentlyAskedQuestion
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString FrequentlyAskedQuestionID;

	UPROPERTY()
	FFortPlayerSurveyCMSQuestion Question;

};

USTRUCT()
struct FFortPlayerSurveyCMSFrequentlyAskedQuestionID
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ID;

};

USTRUCT()
struct FFortPlayerSurveyCMSQuestionContainer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFortPlayerSurveyCMSFrequentlyAskedQuestionID FrequentlyAskedQuestionID;

	UPROPERTY()
	FFortPlayerSurveyCMSQuestion Question;

};

USTRUCT()
struct FFortPlayerSurveyCMSSurvey
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString SurveyID;

	UPROPERTY()
	TArray<FString> SurveyTags;

	UPROPERTY()
	FString Title;

	UPROPERTY()
	TArray<FString> ConditionGroupIDs;

	UPROPERTY()
	TArray<FFortPlayerSurveyCMSCondition> Conditions;

	UPROPERTY()
	TArray<FFortPlayerSurveyCMSQuestionContainer> Questions;

	UPROPERTY()
	TArray<FFortPlayerSurveyCMSCustomTextReplacement> TextReplacementOverrides;

	UPROPERTY()
	bool bRandomizeQuestionOrder;

};

USTRUCT()
struct FFortPlayerSurveyCMSData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FFortPlayerSurveyCMSConditionGroup> ConditionGroups;

	UPROPERTY()
	TArray<FFortPlayerSurveyCMSFrequentlyAskedQuestion> FrequentlyAskedQuestions;

	UPROPERTY()
	TArray<FFortPlayerSurveyCMSCustomTextReplacement> CustomTextReplacements;

	UPROPERTY()
	TArray<FFortPlayerSurveyCMSCustomTextReplacement> WhitelistedTextReplacements;

	UPROPERTY()
	TArray<FFortPlayerSurveyCMSSurvey> Surveys;

	UPROPERTY()
	bool bSurveysEnabled;

};

