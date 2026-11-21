// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CCP_AnimInstance_CyberKarate.generated.h"

UCLASS(MinimalAPI, HideCategories=("AnimInstance"))
class UCCP_AnimInstance_CyberKarate : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Cyber Karate")
	float BackblingAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Cyber Karate")
	bool bSkydiving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Cyber Karate")
	float FrontendSkirtAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Cyber Karate")
	float FrontendNoEmote;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Cyber Karate")
	bool bSkyDivingModeOrSkyDiving;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cyber Karate|Magic Float")
	float FrontendSkirtAlphaRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cyber Karate|Magic Float")
	float FrontendSkirtAlphaRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cyber Karate|Magic Float")
	float FrontendInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cyber Karate|Magic Float")
	float BackblingAlphaA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cyber Karate|Magic Float")
	float BackblingAlphaB;

};

