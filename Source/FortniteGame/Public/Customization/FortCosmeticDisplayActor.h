// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "Customization/CustomizationItemInterface.h"
#include "FortCustomPartTypeEnum.h"
#include "FortCosmeticDisplayActor.generated.h"

class UAthenaCosmeticItemDefinition;
class UChildActorComponent;
class UCustomCharacterPart;
class USkeletalMeshComponent;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Materials"))
class AFortCosmeticDisplayActor : public AActor, public ICustomizationItemInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="MannequinNotifications")
	void OnPartChanged(const UCustomCharacterPart* OldPart, const UCustomCharacterPart* NewPart, EFortCustomPartType::Type PartType);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="MannequinNotifications")
	void OnVariantChanged(FGameplayTag VariantChannel, FGameplayTag OldVariantTag, FGameplayTag NewVariantTag);

	UPROPERTY(EditAnywhere, Category="FortCosmeticDisplayActor", meta=(AllowedClasses="/Script/FortniteGame.AthenaGliderItemDefinition,/Script/FortniteGame.AthenaPickaxeItemDefinition,/Script/FortniteGame.AthenaBackpackItemDefinition,/Script/FortniteGame.AthenaSkyDiveContrailItemDefinition"))
	TObjectPtr<UAthenaCosmeticItemDefinition> CustomizationCosmeticDefinition;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortCosmeticDisplayActor", meta=(AllowPrivateAccess="TRUE", EditInline="true"))
	TObjectPtr<UChildActorComponent> PreviewActorComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortCosmeticDisplayActor", meta=(AllowPrivateAccess="TRUE", EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> SkeletalMeshComponent;

	UPROPERTY(EditAnywhere, Category="FortCosmeticDisplayActor")
	TArray<FMcpVariantChannelInfo> OverrideVariants;

	UPROPERTY(EditDefaultsOnly, Category="Lighting")
	bool bApplyLightingOverrideToChildren;

	UPROPERTY(EditDefaultsOnly, Category="Lighting")
	FLightingChannels LightingChannelsOverride;

};

