// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent_CosmeticBase.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "FortAthenaAISpawnerDataComponent_AIBotCosmeticBase.generated.h"

class AFortAthenaAIBotController;
class UAnimInstance;
class UAthenaCosmeticItemDefinition;
class UAthenaDanceItemDefinition;
class UCustomCharacterPart;
class UFortAIPawnCustomizationDefinition;

UCLASS(Abstract, MinimalAPI)
class UFortAthenaAISpawnerDataComponent_AIBotCosmeticBase : public UFortAthenaAISpawnerDataComponent_CosmeticBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddCosmeticOverrideItemDef(const UAthenaCosmeticItemDefinition* InCosmeticItemToPreview);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void GetAllLoadouts(TArray<FFortAthenaLoadout>& OutLoadouts);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void GetAnimBPOverride(TSubclassOf<UAnimInstance>& OutAnimBPOverride, int32& OutPriority);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void GetCustomCharacterParts(TArray<UCustomCharacterPart*>& OutCustomCharacterParts);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void GetDances(TArray<UAthenaDanceItemDefinition*>& Dances, const AFortAthenaAIBotController* BotController);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void GetLoadout(FFortAthenaLoadout& OutLoadout);

private:
	UPROPERTY(EditAnywhere, Category="Cosmetic", meta=(AllowPrivateAccess="true"))
	TArray<TObjectPtr<UAthenaCosmeticItemDefinition>> CosmeticOverrideList;

	UPROPERTY(EditAnywhere, Category="Cosmetic", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UFortAIPawnCustomizationDefinition> RetargetingDefinition;

};

